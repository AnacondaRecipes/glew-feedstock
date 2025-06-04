#!/bin/bash
set -e

# Build and run custom GLEW test program (skip on macOS to avoid segfault)
if [ "$(uname)" != "Darwin" ]; then
    mkdir -p build
    cd build
    cmake $RECIPE_DIR/test -DCMAKE_BUILD_TYPE=Release
    make
    ./main
    cd ..
fi

# Test GLEW utilities
if command -v glewinfo &> /dev/null; then
    if [ "$(uname)" = "Linux" ] && command -v xvfb-run &> /dev/null; then
        DISPLAY=localhost:1.0 xvfb-run -a glewinfo || true
    else
        glewinfo || true
    fi
fi

if command -v visualinfo &> /dev/null; then
    if [ "$(uname)" = "Linux" ] && command -v xvfb-run &> /dev/null; then
        timeout 10s bash -c "DISPLAY=localhost:1.0 xvfb-run -a visualinfo -display localhost:1.0" || true
    else
        if command -v timeout &> /dev/null; then
            timeout 10s visualinfo || true
        else
            visualinfo || true
        fi
    fi
fi