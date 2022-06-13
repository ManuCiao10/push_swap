# push_swap

[![eardingh's 42 stats](https://badge42.vercel.app/api/v2/cl4bi3xsw007609kvnmtrlu37/stats?cursusId=21&coalitionId=undefined)](https://github.com/JaeSeoKim/badge42)

### rules

• You have 2 stacks named a and b.
• At the beginning:
    - The stack a contains a random amount of negative and/or positive numbers
    which cannot be duplicated.
    - The stack b is empty.

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