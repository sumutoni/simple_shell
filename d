print_env.c: In function ‘print_env’:
print_env.c:20:3: error: value computed is not used [-Werror=unused-value]
   20 |   *env++;
      |   ^~~~~~
print_env.c:21:7: error: assignment to ‘char *’ from incompatible pointer type ‘char **’ [-Werror=incompatible-pointer-types]
   21 |   var = env;
      |       ^
cc1: all warnings being treated as errors
