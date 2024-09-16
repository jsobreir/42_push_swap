# Push_swap
<p style="text-align:center;">Because Swap_push isn’t as natural.</p>

The goal of this project is to create an algorithm capable of ordering a Stack of numbers, using a restricted set of operations.

## Documentation
## Project Goals and Rules
This program orders a stack of numbers passed as parameters using a set of allowed operations:
| Operation | Description                                                                 |
|-----------|-----------------------------------------------------------------------------|
| sa        | Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements. |
| sb        | Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements. |
| ss        | sa and sb at the same time.                                                   |
| pa        | Take the first element at the top of b and put it at the top of a. Do nothing if b is empty. |
| pb        | Take the first element at the top of a and put it at the top of b. Do nothing if a is empty. |
| ra        | Shift up all elements of stack a by 1. The first element becomes the last one. |
| rb        | Shift up all elements of stack b by 1. The first element becomes the last one. |
| rr        | ra and rb at the same time.                                                   |
| rra       | Shift down all elements of stack a by 1. The last element becomes the first one. |
| rrb       | Shift down all elements of stack b by 1. The last element becomes the first one. |
| rrr       | rra and rrb at the same time.                                                 |

## Installing and Using
To download, clone the repository into your device and navigate inside using `cd pipex`, then typing  `make` to compile all the functions and generate the executable pipex, which you can run as follows:

```
./push_swap 10 1 3 4 33 54 23 
```
You can use any list of ints you want. The program should be able to order them accordingly, returning the steps required for that.

## Project Implementation
### Parsing
The program is capable of parsing the numbers given as parameters, either passed as plain numbers or in a single parameter such as `./push_swap "10 1 3 4 33 54 23"`.
### Stacking
The program uses lists to stack the numbers. It creates two stacks: stack A and stack B. Stack A is where the original numbers are innitially passed to. Stack B is the stack used to perform the operations to organize the numbers.
The stacks are defined as follows:
```
typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
}	t_stack;
```

Each node of the list holds a number and a pointer to the next node, which containes the following number on the stack.
To perform the operations I had to write functions that manipulate these lists: `ft_stackaddback`, `ft_stackaddfront`, `ft_stackclear` and `ft_stacklast`, as well as functions that manipulate the stacks: `ft_swap`, `ft_rotate`, `ft_reverse_rotate`, `ft_push`.
### The algorithm
The algorithm is the most interesting part of the project. The goal here is to write an algorithm that sorts the numbers the fastest way possible. The criteria is that if it sorts 500 numbers with less than 5500 operations, the project is attributed maximum score.
To choose the algorithm I was going to use I read about different sorts of algorithms. The ones that stood out were the Radix algorithm and another one called the 'Turkish Algorithm' which was invented by a fellow 42 Student for this project.
My project is based on [this](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) algorithm. Essentially, it works by pre-calculating the price of each move (e.g., the number of moves needed to move a number from Stack A to B) before actually making the move. This method is very efficient for this project as it always ensures the cheapest move is made.

## Disclaimer
At 42 School our projects have to adhere to the 42 Norm of coding standards and good practices. These include:
- Maximum 25 lines per function and 5 functions per file;
- No variable declarations and assignments in the same line;
- Forbiden structures: `for`, `switch`, `goto` and `case`;
- No more than 5 variables per function.

All of my projects strictly adhere to this Norm, that promotes code simplicity and readability.
