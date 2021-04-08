## Creating tests

Create a test case <test_name>.cc in the test directory.  
A test case is just a regular C++ program. On success, exit code must be 0.
Failing the test means exit code is different than 0.

## Running tests

run `make test` to run all tests.  
run `make mytest` to compile your test.
run `make mytest.test` to compile and run your case.

All compiled binaries will be in tests/build.
