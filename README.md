# Using the Dev Container

** This has enabled experimental `import std;` support in the project. **

## In VS Code

### Prequisites

1. You need to have [Docker](https://www.docker.com/get-started/) installed and running. Easiest way to get it is:
   - On Windows just install Docker Desktop and make sure WSL2 backend is enabled.
   - On Linux install docker from installation shell script, provided by docker.
   - On Mac install Docker Desktop. You need Rosetta 2 installed as well, if you are on Apple Silicon.
   - If you do not have Docker installed and you do not want to install it, you can use github codespaces as well, see below. It can be connected to local VS Code as well.
2. You need to have [VS Code](https://code.visualstudio.com/) installed.

### Steps

1. Just open the folder in VS Code and it should prompt you to reopen in the container. If not, press F1 and select *Dev Containers: Reopen in Container*. It should build the container and open the workspace inside it.
2. We use CMake to make our builds, there are two presets defined, one for **Debug** (with debug symbols and no optimizations) and one for **Release** (with optimizations and no debug symbols).
3. You can build the project via *F1 → CMake: Build*. It will use the selected preset (Debug or Release) to build the project. To switch the preset, use *F1 → CMake: Select Configure Preset*.
4. Debugging the project is done via *F5* or *Run → Start Debugging*. If it asks to select an environment, select *Debug (LLDB)*. It should configure and build the project automatically and start debugging.
5. Breakpoints should work out of the box.

### Notes

- If compilation breaks and you do not know why, you can try to remove the `build` folder and run build or debug again.
- If anything breaks beyond repair, can you try to rebuild the container (*F1 → Dev Containers: Rebuild Container*).
- If you do not wish to use the devcontainer, you can delete `.devcontainer` folder, tasks and launch configuration in `.vscode` folder should work locally on Linux environment. Maybe you would need to adjust the paths. It should work as well. Just use at least clang 21.
- VS Code may want you to install some extensions, we recommend to ignore it, as we have everything setup in the devcontainer already. This should now be covered by `settings.json` in `.vscode` folder, so just in case.
- Experimental `import std;` is supported in this project. It works with syntax highlighting and code completion in the devcontainer. However to be fully functional, you need to wait for `clangd` to index everything (couple of minutes) and you need to build the project at least once, so that all modules are properly recognized. 
- If for whatever reason the modules are not recognized, (it will complain about `import std;`), try to restart `clangd` server with command `F1 → clangd: Restart language server`. If that does not work, remove `build` folder and build the project again.
- Importing header unit is still not functional since CMake does not fully support them yet. And we would need to add them manually to the CMake configuration.

## In github codespaces

1. Fork the repo
2. Create a new codespace from the forked repo
   - Menu → Codespaces → New codespace
   - Select, repo, branch, machine etc.
   - Hit Create codespace
3. Wait for code space to build and open
4. You have basically working VS Code in the browser, so proceed as in the VS Code section above (just skip first step).
5. It is possible to open the remote codespace in local VS Code as well, you just click on the left bottom corner with codespace name and select *Open in VS Code Desktop*. It will guide you through the steps (installing github extension and logging in to github). After that, the codespace is opened in local VS Code and you can work as if it was local devcontainer.