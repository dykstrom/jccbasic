# -----------------------------------------------------------------------------

MAIN_INC=main/inc
MAIN_SRC=main/src
TEST_INC=test/inc
TEST_SRC=test/src

TARGET=target

DLL_NAME=jccbasic
DLL=$(TARGET)/$(DLL_NAME).dll

CC=gcc
CC_FLAGS_MAIN=-c -g -Wall -I$(MAIN_INC)
CC_FLAGS_TEST=-c -g -Wall -I$(MAIN_INC) -I$(TEST_INC)

LD=gcc
LD_FLAGS_MAKE=-shared --enable-runtime-pseudo-reloc
LD_FLAGS_LINK=-L$(TARGET) -l$(DLL_NAME)

# -----------------------------------------------------------------------------

HEADERS=\
	$(MAIN_INC)/fix.h \
	$(MAIN_INC)/jccbasic_version.h \
	$(MAIN_INC)/ltrim.h \
	$(MAIN_INC)/rtrim.h \
	$(MAIN_INC)/sgn.h \
	\
	$(TEST_INC)/assert.h

MAIN_OBJS=\
	$(TARGET)/fix.o \
	$(TARGET)/jccbasic_version.o \
	$(TARGET)/ltrim.o \
	$(TARGET)/rtrim.o \
	$(TARGET)/sgn.o

TEST_OBJS=\
	$(TARGET)/test_fix.o \
	$(TARGET)/test_jccbasic_version.o \
	$(TARGET)/test_ltrim.o \
	$(TARGET)/test_rtrim.o \
	$(TARGET)/test_sgn.o

TEST_EXES=\
	$(TARGET)/test_fix.exe \
	$(TARGET)/test_jccbasic_version.exe \
	$(TARGET)/test_ltrim.exe \
	$(TARGET)/test_rtrim.exe \
	$(TARGET)/test_sgn.exe

# -----------------------------------------------------------------------------

.PHONY: all clean

all: $(TARGET) $(DLL) $(TEST_EXES)

clean:
	-rm -rf $(TARGET)

# -----------------------------------------------------------------------------

$(TARGET):
	-mkdir $(TARGET)

$(TARGET)/%.o: $(MAIN_SRC)/%.c $(HEADERS)
	$(CC) -o $@ $(CC_FLAGS_MAIN) $<

$(DLL): $(MAIN_OBJS)
	$(LD) -o $@ $(LD_FLAGS_MAKE) $^

# -----------------------------------------------------------------------------

$(TARGET)/%.o: $(TEST_SRC)/%.c $(HEADERS) $(DLL)
	$(CC) -o $@ $(CC_FLAGS_TEST) $<

$(TARGET)/%.exe: $(TARGET)/%.o
	$(LD) -o $@ $(LD_FLAGS_LINK) $<

# -----------------------------------------------------------------------------
