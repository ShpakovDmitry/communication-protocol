# -*-make-*- communication-protocol Copyright (C) 2024 Dmitry Shpakov
# 
#   file: Makefile
# author: ShpakovDmitry
#   date: 2024-08-22
# 
#

.PHONY := all clean
.DEFAULT_GOAL := all

TARGET := communicationProtocol

CXX := g++

SOURCE_DIR := .
BUILD_DIR := build
INC_DIRS := 0_physical_layer
INC_DIRS += 1_data_link_layer
INC_DIRS += 2_network_layer
INC_DIRS += 3_transport_layer
INC_DIRS += 4_session_layer
INC_DIRS += 5_presentation_layer
INC_DIRS += 6_application_layer
INC_DIRS += abstract_layer
INC_DIRS += protocol_stack

SRC_FILES := $(shell find $(SOURCE_DIR) -name "*.cpp")
OBJ_FILES := $(SRC_FILES:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJ_FILES:.o=.d)

INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CXX_FLAGS := $(INC_FLAGS) -MMD -MP
CXX_FLAGS += -Wall -Werror
CXX_FLAGS += -Wextra -Wcast-align -Wconversion -Wsign-conversion
CXX_FLAGS += -Wold-style-cast
CXX_FLAGS += -Wshadow -Wlogical-op -Wsuggest-override -Wsuggest-final-types
CXX_FLAGS += -Wsuggest-final-methods -pedantic

all: $(BUILD_DIR) $(BUILD_DIR)/$(TARGET) $(BUILD_DIR)/$(OUTPUT_LIB_FILE)

$(BUILD_DIR):
	mkdir --parents $@

$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir --parents $(dir $@)
	$(CXX) $(CXX_FLAGS) -c $< -o $@

$(BUILD_DIR)/$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXX_FLAGS) $(LD_FLAGS) $(OBJ_FILES) -o $@

run: $(BUILD_DIR)/$(TARGET)
	clear
	./$(BUILD_DIR)/$(TARGET)

clean:
	rm -rf $(BUILD_DIR)

