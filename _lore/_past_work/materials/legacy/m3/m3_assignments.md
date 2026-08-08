 M3T1
Hide Details
For this assignment you will create a program to match the following specifications.
Ask the user to enter the length and width of two rectangles, then display the area of both.
Submit a screenshot and the source code in a .cpp file as usual. 
(Note: In the related video, I first solve the problem for just one rectangle, then add code to calculate it for both. Make sure you calculate the answer for both.)
video for M3T1 and M3T2 - https://youtu.be/z0Chr0qlteI
NOTE: By this point in the class, you should be comfortable uploading a copy of your program to your GitHub repository for CSC134 any time you submit something. Please contact me if you have questions about this process.
Here's the starter code:

m3t1_norris.cpp Click for more options
 
Item
M3T2
M3T2 item options M3T2
Hide Details
This program builds on the M3T1 program. (When adding to an existing program, you should make a copy of the file, rename it as needed, and then start adding the new features.)
For this assignment you will create a program to match the following specifications.
Ask the user to enter the length and width of two rectangles, then display the area of both.
Tell the user which rectangle has the larger area, or if they are the same area.
Here's the version from class: 
m3t1_norris (1).cpp Click for more options
 
Item
M3LAB1
M3LAB1 item options M3LAB1
Hide Details
Choices with the if statement.
First, please read through all three examples in the included ZIP file. This sample program simulates a very simple game show, where the user makes a choice and then finds out what they've won.
if_example_source.zip Click for more options  
The first program is a simple 'Hello World', before we start adding features to the program.
Program two uses the if statement to print different results based on a user choice.
Program three uses some advanced techniques we will get to soon, adding additional functions (also called methods) to the program. (So far, we've only had one method, which is main(). If program three causes you confusion and you're having trouble with it, then that's fine -- you can base your program on program two for now.)
The Assignment
Use the examples given here as a basis (Program Two or Program Three, your choice). Instead of Door #1 and Door #2, you should have some other choice, with other consequences. For example, a combat game, where the user types 'fight' or 'run'. 
I recommend you look through each file in order to see how the program is built. Rather than copying and pasting the example, try to type it up yourself.

Item
M3T3 - RNG
M3T3 - RNG item options M3T3 - RNG
Hide Details
M3T3 - Random Numbers
References:
Zybooks - Pseudorandom Numbers - section 4.17
Zybooks - switch statements, nested if statements, flowcharts - sections 3.8, 3.9, 3.10.
Random numbers in c (Bro Code): https://www.youtube.com/watch?v=CJ37J_Cdd8Q
My short stream on 2/19: https://www.youtube.com/live/P_MwrQaXQJI?si=qwv2OANUopS2938y
and the code I wrote from that stream: 
Started with: 
m3t3_norris.cpp Click for more options
Ended with: 
m3_random.cpp Click for more options
 
If statements + Random numbers -> Games
 
We'll start working on building a program which simulates the game of "Craps". To start, we'll just figure out how to do dice rolls, then the decision tree.
For our first pass, we'll just try to get the first "win or lose" rolls working, and leave the "point" system for later.
Quick Introduction if you're not familiar with the casino game: https://youtu.be/qNsSpNm_iCw
 How to play Craps (wikihow, the best instruction site ever): https://www.wikihow.com/Play-Craps
Here's the full Craps flowchart (stopping after one roll)

Click for more options
 
For this assignment, we'll get as far as we can!
I recommend starting with just checking for "craps" (instant loss) and the instant wins, and after that, you can try to get "points" working.
Item
M3LAB2
M3LAB2 item options M3LAB2
Hide Details
CSC 134 - M3LAB2: Number Grade to Letter Grade Conversion Program
PDF Version: 
csc134_m3lab2.pdf Click for more options csc134_m3lab2.pdf - Alternative Formats
 
Objective:
In this lab, you will create a C++ program that converts numerical grades into letter grades based on the following criteria:

    A: 90 - 100
    B: 80 - 89
    C: 70 - 79
    D: 60 - 69
    F: 0 - 59

Instructions:

    Program Requirements:
        Create a C++ program that asks the user to input a numerical grade.
        Because this uses ranges, you will probably need Boolean AND "&&" or Boolean OR "||" operators. See Zybooks 3.12.
        Use conditional statements (if-else) to determine the corresponding letter grade.
        Display the letter grade to the user.
    Implementation:
        Begin by prompting the user to enter a numerical grade.
        Use appropriate variables to store the numerical grade entered by the user.
        Implement conditional statements to determine the letter grade based on the numerical input.
        Display the resulting letter grade to the user.
    Testing:
        Test your program with different numerical grades to ensure it accurately converts them to the corresponding letter grades.
        Verify that the program handles edge cases such as the minimum and maximum numerical grades for each letter grade range.
    Submission:
        Submit your C++ program file (.cpp) via the designated platform or as instructed by your instructor.
        Ensure your program is well-commented and follows best coding practices.

Example Output:

Enter your numerical grade: 85 Your letter grade is: B 

Grading Rubric:

    Correctness of the program logic: 40%
    Proper implementation of input/output: 20%
    Adherence to coding standards and best practices: 20%
    Overall code structure and readability: 20%

-generated by teacherbot
Item
M3HW
M3HW item options M3HW
Hide Details
M3HW1
These instructions are also included in the attached PDF. (The formatting in the PDF may be easier to read.)
csc134_m3hw1.pdf Click for more options csc134_m3hw1.pdf - Alternative Formats
 


Instructions:

All questions involve using if statements to make the program perform different behavior, based on user input. You may want to review cin, cout, and if.

Bronze (max 80/100): Complete any two questions.
Silver (max 90/100): Complete any three questions.
Gold (max 100/100): Complete all four questions.

Please add to your top of file comment block a note on which tier you are attempting.
Example:

// CSC 134
// M3HW1 - Silver
// Name
// Date

For setting up your program, you have three options.

First, you can simply make one file for each question. (M3HW1_Name_Q1, for example). This is the easiest but requires the most effort, since you have to upload each file.

Second, you could answer all the questions in main, with a cout message between them.
Example:

// Question 1
cout << “Question 1” << endl;
// Question 1 code goes here

// Question 2
Cout << “Question 2” << endl;
// Question 2 code goes here

// etc.

If you do this, remember you can’t declare the same name for a variable twice, so if you have int x; in Question 1, you can’t also have int x; in Question 2. Using different variable names gets around this. (Not that you should have a variable called “x” anyway, it’s not descriptive.)

Third, and the method we’ll use once we fully cover functions, is to use functions, which we will learn more about later.
Here's that example: 
m3hw_example.c++ Click for more options
 
There's also the version using while loops: m3hw_example_while_loop.c++ Click for more options
 

The Questions

Question 1. Write a very simple “chat bot” that has a very short conversation. A sample transcript of the program output follows, write yours so that it follows the script. (User input is in bold). If your output is different, but the behavior is about the same (it answers in three different ways), that is fine.


Sample Run 1
Hello, I’m a C++ program!
Do you like me? Please type yes or no.
yes
That’s great! I’m sure we’ll get along.

Sample Run 2
Hello, I’m a C++ program!
Do you like me? Please type yes or no.
no
Well, maybe you’ll learn to like me later.

Sample Run 3
Hello, I’m a C++ program!
Do you like me? Please type yes or no.
(any input other than ‘yes’ or ‘no’)
If you’re not sure… that’s OK.

(Notes: If you’d like to see a more complicated chatbot in action, try out Eliza: https://www.masswerk.at/elizabot/ is one version. You might try asking it for advice about your c++ homework. It’s a really good listener.)
 


Question 2. Use the “receipt calculator” program you wrote in the previous module as a base.
 Add this functionality to the program:

Ask them to enter the price of the meal.

Ask them if the order is dine in or takeaway. (You might do this by a line such as “Please enter 1 if the order is dine in, 2 if it is to go”).

If the order is dine in, add a 15% tip. (This is similar to how you already handled tax, you calculate a $ tip based on the meal price multiplied by the tip percentage.)

Then print the meal price, the tax, the tip (if any), and finally the total amount due, using a receipt format like from the previous assignment.



Question 3. Create a simple “Choose Your Own Adventure” game, where the user types in commands and the program tells a simple story. You may wish to use the M3LAB2 assignment for an idea of where to start.

In this game, you should offer the user a choice of two actions. One answer leads to a game over, and the other leads to a second choice of two actions. One answer leads to defeat, and one to victory.

If a CYOA game doesn’t interest you, you can set up the same structure to ask the user to answer some questions for a quiz, such as “What Harry Potter house are you?”

(Notes: You will probably need to use a nested if structure, so that only one of the two answers to the first question leads to the second question. The chapter gives a few examples.

One way to try out this kind of game if you have an Alexa enabled device is to say “Alexa, Skyrim”. I’m not kidding.

Another, very silly, example of a Choose Your Own Adventure is in the “Adventure Call” skits from the Scottish TV program “Limmy’s Show”. If you like absurd humor, you might check them out: https://www.youtube.com/playlist?list=PL14FE43CDC4AA21F0 )



Question 4. Write a simple “Math practice” program that meets the following requirements.

The program should generate two single digit numbers at random.
 The program should print out the numbers as a simple addition problem.

The program should ask the user to enter the answer.

Finally, the program will tell the user whether or not their answer was correct.

Sample Run (your output may vary from this format)

What is 4 plus 5?
8
Incorrect.

(Notes: The previous chapter explains how to generate pseudorandom numbers.)
Item
M3BONUS
M3BONUS item options M3BONUS
Hide Details
M3Bonus - exploratory programming
This is optional -- you can instead get caught up on your M3 assignments today.
For this assignment, I'd like you to take craps, or some other game type you're interested in, and see how far you can get with AI Assisted Development.
I do find that starting with some existing code may make things easier, but feel free to experiment.
Things you may want to "prompt" (ask about):

    making a random number function you can call repeatedly
    adding loops to catch bad input
    what makes a good simple game?

A workable starting prompt:
"I'm a first year C++ programmer, and we've just learned if statements. My instructor wanted me to ask you, as a C++ expert, how to build on that to make a simple game that does (GAME IDEA). He said it's fine to use loops and functions, but don't get more complicated than that."
I'll also attach the 3/5 demo of multiple functions to this file below. 
m3hw_example_while_loop.c++ Click for more options
 
