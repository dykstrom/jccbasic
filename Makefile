# -----------------------------------------------------------------------------

INC=src/inc/c
SRC=src/main/c
TEST=src/test/c

DLL_NAME=jccbasic

DLL_DIR=target_dll
EXE_DIR=target_exe

CC=gcc
CC_FLAGS=-I$(INC) -g -Wall

LD=gcc
LD_MAKE_FLAGS=-shared --enable-runtime-pseudo-reloc
LD_LINK_FLAGS=-L$(DLL_DIR) -l$(DLL_NAME)

# -----------------------------------------------------------------------------

DEPS=\
	$(INC)/fix.h \
	$(INC)/jccbasic_version.h \
	$(INC)/sgn.h

DLL_OBJS=\
	$(DLL_DIR)/fix.o \
	$(DLL_DIR)/jccbasic_version.o \
	$(DLL_DIR)/sgn.o

DLL=$(DLL_DIR)/$(DLL_NAME).dll

EXE_OBJS=\
	$(EXE_DIR)/test_fix.o \
	$(EXE_DIR)/test_jccbasic_version.o \
	$(EXE_DIR)/test_sgn.o

EXE=\
	$(EXE_DIR)/test_fix.exe \
	$(EXE_DIR)/test_jccbasic_version.exe \
	$(EXE_DIR)/test_sgn.exe

# -----------------------------------------------------------------------------

.PHONY: all clean

all: $(DLL_DIR) $(DLL) $(EXE_DIR) $(EXE)

clean:
	-rm -rf $(DLL_DIR) $(EXE_DIR)

# -----------------------------------------------------------------------------

$(DLL_DIR):
	-mkdir $(DLL_DIR)

$(DLL_DIR)/%.o: $(SRC)/%.c $(DEPS)
	$(CC) $(CC_FLAGS) -c -o $@ $<

$(DLL): $(DLL_OBJS)
	$(LD) $(LD_MAKE_FLAGS) -o $@ $^

# -----------------------------------------------------------------------------

$(EXE_DIR):
	-mkdir $(EXE_DIR)

$(EXE_DIR)/%.o: $(TEST)/%.c $(DEPS)
	$(CC) $(CC_FLAGS) -c -o $@ $<

$(EXE_DIR)/%.exe: $(EXE_DIR)/%.o
	$(LD) $(LD_LINK_FLAGS) -o $@ $<

# -----------------------------------------------------------------------------
