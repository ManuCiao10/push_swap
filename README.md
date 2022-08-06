# push_swap

<img width="1030" alt="Screen Shot 2022-08-06 at 1 57 48 PM" src="https://user-images.githubusercontent.com/89024276/183260478-3c5157f1-17aa-4baf-a044-9c8a0790836a.png">


### The “push_swap” program
* You have to write a program named push_swap which will receive as an argument
the stack a formatted as a list of integers. The first argument should be at the top
of the stack (be careful about the order).
* The program must display the smallest list of instructions possible to sort the stack
a, the smallest number being at the top.
* Instructions must be separaed by a ’\n’ and nothing else.
* The goal is to sort the stack with the minimum possible number of operations.
During defence we’ll compare the number of instructions your program found with
a maximum number of operation tolerated. If your program either displays a list
too big or if the list isn’t sorted properly, you’ll get no points.
* In case of error, you must display Error followed by a ’\n’ on the standard error.
Errors include for example: some arguments aren’t integers, some arguments are
bigger than an integer, and/or there are duplicates.

### Rules

• You have 2 stacks named a and b.
• At the beginning:
    - The stack a contains a random amount of negative and/or positive numbers
    which cannot be duplicated.
    - The stack b is empty.

### Movements

<img width="607" alt="stack_a_to_b" src="https://user-images.githubusercontent.com/89024276/183260260-dc13410a-22ce-45eb-911f-f9b30259c0fa.png">
<img width="267" alt="stack_b_to_a" src="https://user-images.githubusercontent.com/89024276/183260261-c2a17e1b-0793-47ff-98be-2505d8ef2d08.png">

### Command

| Command       | Description                                                                           |
| ------------- | --------------------------------------------------------------------------------------| 
| <b>sa</b>     | swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements). |
| <b>sb</b>     | swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements). |
| <b>ss</b>     | sa and sb at the same time. |
| <b>pa</b>     | push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty. |
| <b>pb</b>     | push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty. |
| <b>ra</b>     | rotate a - shift up all elements of stack a by 1. The first element becomes the last one. |
| <b>rb</b>     | rotate b - shift up all elements of stack b by 1. The first element becomes the last one. |
| <b>rr</b>     | ra and rb at the same time. |
| <b>rra</b>    | reverse rotate a - shift down all elements of stack a by 1. The flast element becomes the first one. |
| <b>rrb</b>    | reverse rotate b - shift down all elements of stack b by 1. The flast element becomes the first one. |
| <b>rrr</b>    | rra and rrb at the same time. |

### Execution example
```
$>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
6
$>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
OK
$>
```
