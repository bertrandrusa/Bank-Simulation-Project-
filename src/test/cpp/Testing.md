# Guidelines for Testing Standard Output

Below is an example of how to use the `buffer` attribute of our test fixtures to validate expected output to the terminal window:

```c++
TEST_F( CSC232BaseTestFixture, DISABLED_TestExpectedOutput )
{
    std::cout << "Google Test" << std::endl;
    const std::string expected { "Google Test\n" };
    const std::string actual { buffer.str( ) };
    EXPECT_STREQ( expected.c_str( ), actual.c_str( ) );
}
```

In the event that you want to validate failed assertions, use `EXPECT_DEATH` as follows:

```c++
TEST_F( DISABLED_CSC232ChildClassTestFixture, ValidateFailedAssertionTest )
{
    EXPECT_DEATH( {
        assert( false ); // some line(s) of code that will cause a failed assertion
    }, ".*failed.*" );
}
```
