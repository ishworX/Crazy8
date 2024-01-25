# Crazy8-s-Card-Game

For testing...
"g++ -o a.exe -std=c++11 -Wall -g main.cpp"

Todo
- Implement functions for Human players...
- Make players can choose Suit when they play 8s...


CARD VALUES/SCORING
The player who is the first to have no cards left wins the game. The winning player collects from each other player the value of the cards remaining in that player’s hand as follows:
- Each eight = 50 points
- Each K, Q, J or 10 = 10 points
- Each ace = 1 point
- Each other card is the pip value

From the PDF file...

- A report on the team’s learning experience

SOFTWARE TOOLS
1. The project is to be developed in C++.
2. A Makefile will be created for building your game, running tests, checking quality of code,
and so forth.
3. All artifacts (source code, documentation, reports, and reported issues) will be kept in a
provided repository on the department’s Gitlab server.
4. Cppcheck will be used for static analysis
5. Cpplint will be used for checking programming style using the configuration provided with
the assignments.
6. Memcheck (i.e. Valgrind) will be used for checking memory leaks.
7. Gitlab Pipelines will be used for continuous integration.

REPOSITORY ORGANIZATION
- Your repository must be organized in a logical fashion (i.e. do not have all files at the top level!).
- Your repository is required to have at least the following top-level directories and files (so the grader can easily find the files and build your project), but you can add other directories according to your project needs:

• Makefile – a Makefile that has the following targets:
  - compile – compiles the project.
  - test – compiles and runs the unit test cases.
  - memory – runs memcheck on the project.
  - style – runs cpplint.py on the project.
  - static – runs cppcheck on the project.

• src - the implementation files (.cpp)
  - game – contains the main.cpp for running the game

• include – the header files (.h)

• test – the GTest test files, including the main.cpp to run the tests

• docs – contains the project documentation and report, with the following sub-directories:
  - report – contains the team’s PDF report on their learning experience (both positive and negative).
