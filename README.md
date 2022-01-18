# ComputerOrganization_CEG3310
This repository contains some of the code I wrote for my Computer Organization class.

/Lab05: This project is to create a program that is supposed to learn after each run. It's sort of like 20 questions. It uses a binary tree to accomplish this.
  /actual: the actual lab I created and submitted
  /Bad: my first attempt that I failed at
  
/lab6: This is the project I'm most proud of to this day (1/18/2022). There isn't even a C or C++ file in here. It's just a .txt. The goal of this project was to take a C program
  and code it using LC3 assembly language using a stack. I started coding this project as I always do: just go, don't plan anything. I got pretty close to making it work within an
  hour or two, but ultimately there was a bug that had me stuck for another hour or two. After becoming frustrated, I stopped coding and attempted to come to a better understanding
  of the project. That is this .txt file.
  
    Lines 1 - 21:   The C code we need to change into assembly language
    Lines 27 - 36:  Sample output + my own comments detailing what my code will do to print the output
    Lines 38 - 46:  Dummed down version to show pattern of moving (with vague parameters) and printing (with vague parameters)
                    Explicit version showing moves and prints with the specific integers they will print
                    Index notation based on R5: where these numbers are located on the stack relative to R5
    Lines 48 - 143: What each stack frame will look like along with comments detailing events such as MAIN, MOVE, PRINT, MOVE 2, REMOVE STACKFRAME, JUMP, HALT
    Lines 145 - 254: A much more visual representation of what the code will be doing
    Lines 258 - 681: The actual assembly code I implemented.
    
    The reason why I'm so proud of this project is because it worked the first time I ran it. Given, there were -- and I believe still are since I can't see them in my IDE --
    syntax errors. Although, maybe there aren't because copying and pasting from my IDE caused errors in spacing that I had to fix in the LC3 simulator. Either way, I'm just happy
    I put so much thought into it and got it to work first try.
