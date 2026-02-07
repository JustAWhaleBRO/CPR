.PHONY: build clean help list run run-debug run-nodebug test test-debug test-nodebug

# Project root is where this Makefile lives
PROJECT_ROOT := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
BUILD_DIR := $(PROJECT_ROOT)cmake-build-debug

help:
	@echo "=== LeetCode/AtCoder Makefile ==="
	@echo ""
	@echo "Quick Start:"
	@echo "  make run <target>              - Run all tests without debug"
	@echo "  make run-debug <target>        - Run all tests with debug output"
	@echo ""
	@echo "Test Commands:"
	@echo "  make run <target>                    - Run all tests, no debug"
	@echo "  make run <target> <testname>         - Run specific test, no debug"
	@echo "  make run-debug <target>              - Run all tests with debug"
	@echo "  make run-debug <target> <testname>   - Run specific test with debug"
	@echo "  make test <target> [testname]        - Alias for 'make run'"
	@echo "  make test-debug <target> [testname]  - Alias for 'make run-debug'"
	@echo ""
	@echo "Build Commands:"
	@echo "  make build       - Build all targets"
	@echo "  make clean       - Clean build directory"
	@echo "  make list        - List all available targets"
	@echo ""
	@echo "Examples:"
	@echo "  make run l-deque                   - All tests, no debug"
	@echo "  make run-debug l-deque             - All tests with debug"
	@echo "  make run l-deque Sample1           - Sample1 test, no debug"
	@echo "  make run-debug l-deque Sample1     - Sample1 test with debug"
	@echo "  make run i-coins                   - All i-coins tests"
	@echo "  make run-debug h-grid1 Sample2     - h-grid1 Sample2 with debug"
	@echo ""
	@echo "AtCoder Submission:"
	@echo "  extract <problem>    - Extract submission code (must be in at_coder/)"
	@echo "                         Example: cd src/at_coder && extract i-coins"
	@echo ""
	@echo "Documentation:"
	@echo "  README.md                    - Project overview and quick start"
	@echo "  DEBUG_CONTROL_SUMMARY.md     - Complete command reference"
	@echo "  harness/DEBUG_QUICK_REF.md   - Debug macro reference"
	@echo ""

# Build and run WITHOUT debug output: make run TARGET [TESTNAME]
run:
	@if [ -z "$(filter-out $@,$(MAKECMDGOALS))" ]; then \
		echo "Usage: make run TARGET [TESTNAME]"; \
		echo "Example: make run l-deque"; \
		echo "Example: make run l-deque Sample1"; \
		exit 1; \
	fi
	@TARGET="$(word 1,$(filter-out $@,$(MAKECMDGOALS)))"; \
	TESTNAME="$(word 2,$(filter-out $@,$(MAKECMDGOALS)))"; \
	cmake --build $(BUILD_DIR) --target $$TARGET > /dev/null && \
	$(BUILD_DIR)/$$TARGET $$TESTNAME

# Build and run WITH debug output: make run-debug TARGET [TESTNAME]
run-debug:
	@if [ -z "$(filter-out $@,$(MAKECMDGOALS))" ]; then \
		echo "Usage: make run-debug TARGET [TESTNAME]"; \
		echo "Example: make run-debug l-deque"; \
		echo "Example: make run-debug l-deque Sample1"; \
		exit 1; \
	fi
	@TARGET="$(word 1,$(filter-out $@,$(MAKECMDGOALS)))"; \
	TESTNAME="$(word 2,$(filter-out $@,$(MAKECMDGOALS)))"; \
	cmake --build $(BUILD_DIR) --target $$TARGET > /dev/null && \
	DEBUG_ENABLED=1 $(BUILD_DIR)/$$TARGET $$TESTNAME

# Alias for run
test:
	@$(MAKE) run $(filter-out $@,$(MAKECMDGOALS))

# Alias for run-debug
test-debug:
	@$(MAKE) run-debug $(filter-out $@,$(MAKECMDGOALS))

# Build all
build:
	@echo "Building all targets..."
	cmake --build $(BUILD_DIR) -j 8

# Clean
clean:
	@echo "Cleaning build directory..."
	rm -rf $(BUILD_DIR)

# List available targets - automatically detect all folder structures
list:
	@echo "=== Available Targets ==="
	@echo ""
	@for dir in $(PROJECT_ROOT)src/*/; do \
		if [ -d "$$dir" ]; then \
			category=$$(basename "$$dir"); \
			echo "=== $$category ==="; \
			if [ -d "$$dir"educational_dp_contest ]; then \
				ls -d "$$dir"educational_dp_contest/*/ 2>/dev/null | xargs -n1 basename | sort; \
			else \
				ls -d "$$dir"*/ 2>/dev/null | xargs -n1 basename | sort; \
			fi; \
			echo ""; \
		fi; \
	done
	@echo "=== Other (standalone files) ==="
	@for file in $(PROJECT_ROOT)src/*.cpp; do \
		if [ -f "$$file" ]; then \
			basename "$$file" .cpp; \
		fi; \
	done

# Catch-all to allow 'make run TARGET' without errors
%:
	@:

.DEFAULT_GOAL := help

