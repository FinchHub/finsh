# finsh
A command interpreting shell built for learning C and low-level Linux.

## What it Does
Finsh is my own take on a shell which can interpret and execute commands. It is a learning project first and foremost, and is not meant to be an actual, usable replacement to the likes of Bash or Zsh. The goal, however, is to build it out enough that I can use it for basic, everyday tasks without a noticeable difference 
in function.

## Project Status
| Version | Tasks to Complete                                                         | Status      |
|---------|---------------------------------------------------------------------------|-------------|
| v1      | Basic interpretation of single-argument coreutil commands (ls, pwd, etc.) | Done        |
| v2      | Interpretation of multi-argument commands                                 | Done        |
| v3      | Built-in commands (cd, pwd, exit, help, etc.)                             | Not Started |
| v4      | Pipes                                                                     | Not Started |
| v5      | Redirection (ls > example.txt, etc.)                                      | Not Started |
| v6      | Signal handling, shell history, dynamic prompt, readline integration      | Not Started |

## Additional To-Do Tweaks:
- v2: Multi-argument commands work but don't respect things like quotes, for example: `git commit -m "Added x to y and z"` won't handle the message correctly. No idea where to start on fixing this but it's on the wishlist.
