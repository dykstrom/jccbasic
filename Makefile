# -----------------------------------------------------------------------------

MAIN_INC=main/inc
MAIN_SRC=main/src
TEST_INC=test/inc
TEST_SRC=test/src

DLL_NAME=jccbasic

DLL_DIR=target_dll
EXE_DIR=target_exe

CC=gcc
CC_FLAGS=-c -g -Wall

LD=gcc
LD_MAKE_FLAGS=-shared --enable-runtime-pseudo-reloc
LD_LINK_FLAGS=-L$(DLL_DIR) -l$(DLL_NAME)

# -----------------------------------------------------------------------------

DEPS=\
	$(MAIN_INC)/fix.h \
	$(MAIN_INC)/jccbasic_version.h \
	$(MAIN_INC)/sgn.h

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

all: $(DLL_DIR) $(EXE_DIR) $(DLL) $(EXE)

clean:
	-rm -rf $(DLL_DIR) $(EXE_DIR)

# -----------------------------------------------------------------------------

$(DLL_DIR):
	-mkdir $(DLL_DIR)

$(DLL_DIR)/%.o: $(MAIN_SRC)/%.c $(DEPS)
	$(CC) -o $@ $(CC_FLAGS) -I$(MAIN_INC) $<

$(DLL): $(DLL_OBJS)
	$(LD) -o $@ $(LD_MAKE_FLAGS) $^

# -----------------------------------------------------------------------------

$(EXE_DIR):
	-mkdir $(EXE_DIR)

$(EXE_DIR)/%.o: $(TEST_SRC)/%.c $(DEPS)
	$(CC) -o $@ $(CC_FLAGS) -I$(MAIN_INC) -I$(TEST_INC) $<

$(EXE_DIR)/%.exe: $(EXE_DIR)/%.o
	$(LD) -o $@ $(LD_LINK_FLAGS) $<

# -----------------------------------------------------------------------------
