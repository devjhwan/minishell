#!/bin/bash

# Check if Homebrew is installed
if ! command -v brew &> /dev/null; then
    # Create the directory if it doesn't exist
    mkdir -p ~/goinfre/homebrew

    # Install Homebrew in the target directory
    curl -L https://github.com/Homebrew/brew/tarball/master | tar xz --strip 1 -C ~/goinfre/homebrew

    # Add Homebrew to the PATH
    export PATH=~/goinfre/homebrew/bin:$PATH

    echo "Homebrew has been installed and added to the PATH."
else
    echo "Homebrew is already installed."
fi

brew install readline

export LDFLAGS="-L/goinfre/$USER/homebrew/opt/readline/lib"
export CPPFLAGS="-I/goinfre/$USER/homebrew/opt/readline/include"

echo "Readline has been installed."