include makefile.macro

SRC=$(wildcard $(SRC_PATH)/*.cpp)
OBJ+=$(foreach n,$(SRC),$(LIB_PATH)/$(notdir $(subst .cpp,.o,$(n))))

$(shell mkdir -p $(LIB_PATH))

TARGET=$(OUT_PATH)/screenVideo

all:$(TARGET)


$(TARGET):$(OBJ)
	$(LD) -o $@ $? $(LDFLAG)
$(OBJ):$(SRC)
	$(CC) $(PARAM) -o $@ $(SRC_PATH)/$(notdir $*).cpp $(CFLAG)

clean:
	$(RM) -vf $(OBJ)
	$(RM) -vf $(TARGET)
