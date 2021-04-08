## Creating tests

Create a test case <test_name>.cc in the test directory.  
A test case is just a regular C++ program. On success, exit code must be 0.
Failing the test means exit code is different than 0.

I recommend using the CHECK macro, for which you need to `#include <utils/tests.h>` from your test file. Before exiting main, add `TEST_END(argv);` to print
a summary of all the CHECKS.

## Running tests

run `make test` to run all tests.  
run `make mytest` to compile your test.
run `make mytest.test` to compile and run your case.

All compiled binaries will be in tests/build.
