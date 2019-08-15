# -----------------------------------------------------------------------------

MAIN_INC=main/inc
MAIN_SRC=main/src
TEST_INC=test/inc
TEST_SRC=test/src

BIN=bin

DLL_NAME=jccbasic
DLL=$(BIN)/$(DLL_NAME).dll

CC=gcc
CC_FLAGS_MAIN=-c -g -Wall -I$(MAIN_INC)
CC_FLAGS_TEST=-c -g -Wall -I$(MAIN_INC) -I$(TEST_INC)

LD=gcc
LD_FLAGS_MAKE=-shared --enable-runtime-pseudo-reloc
LD_FLAGS_LINK=-L$(BIN) -l$(DLL_NAME)

# -----------------------------------------------------------------------------

HEADERS=\
	$(MAIN_INC)/date_time.h \
	$(MAIN_INC)/fix.h \
	$(MAIN_INC)/hex.h \
	$(MAIN_INC)/jccbasic_version.h \
	$(MAIN_INC)/ltrim.h \
	$(MAIN_INC)/oct.h \
	$(MAIN_INC)/rtrim.h \
	$(MAIN_INC)/sgn.h \
	$(MAIN_INC)/str.h \
	$(MAIN_INC)/timer.h \
	\
	$(TEST_INC)/assert.h

MAIN_OBJS=\
	$(BIN)/date_time.o \
	$(BIN)/fix.o \
	$(BIN)/hex.o \
	$(BIN)/jccbasic_version.o \
	$(BIN)/ltrim.o \
	$(BIN)/oct.o \
	$(BIN)/rtrim.o \
	$(BIN)/sgn.o \
	$(BIN)/str.o \
	$(BIN)/timer.o

TEST_OBJS=\
	$(BIN)/test_date_time.o \
	$(BIN)/test_fix.o \
	$(BIN)/test_hex.o \
	$(BIN)/test_jccbasic_version.o \
	$(BIN)/test_ltrim.o \
	$(BIN)/test_oct.o \
	$(BIN)/test_rtrim.o \
	$(BIN)/test_sgn.o \
	$(BIN)/test_str.o \
	$(BIN)/test_timer.o

TEST_EXES=\
	$(BIN)/test_date_time.exe \
	$(BIN)/test_fix.exe \
	$(BIN)/test_hex.exe \
	$(BIN)/test_jccbasic_version.exe \
	$(BIN)/test_ltrim.exe \
	$(BIN)/test_oct.exe \
	$(BIN)/test_rtrim.exe \
	$(BIN)/test_sgn.exe \
	$(BIN)/test_str.exe \
	$(BIN)/test_timer.exe

# -----------------------------------------------------------------------------

.PHONY: all clean

.PRECIOUS: $(BIN)/%.o

all: $(BIN) $(DLL) $(TEST_EXES)

clean:
	-rm -rf $(BIN)

# -----------------------------------------------------------------------------

$(BIN):
	-mkdir $(BIN)

$(BIN)/%.o: $(MAIN_SRC)/%.c $(HEADERS)
	$(CC) -o $@ $(CC_FLAGS_MAIN) $<

$(DLL): $(MAIN_OBJS)
	$(LD) -o $@ $(LD_FLAGS_MAKE) $^

# -----------------------------------------------------------------------------

$(BIN)/%.o: $(TEST_SRC)/%.c $(HEADERS) $(DLL)
	$(CC) -o $@ $(CC_FLAGS_TEST) $<

$(BIN)/%.exe: $(BIN)/%.o
	$(LD) -o $@ $(LD_FLAGS_LINK) $<

# -----------------------------------------------------------------------------
