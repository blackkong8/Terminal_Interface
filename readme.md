# Useful Interface for OSX Terminal
## Support
* Get Terminal Size
* Terminal RawMode Enable/Disable
* Get Mouse Location
* Create Img
* Lambda

## Usage
### terminal_size.h
```terminal_size get_terminal_size(void);```

```
struct terminal_size
{
    int row, col;
};
```

### raw_mode.h
```void raw_mode(state State);```
```
typedef enum
{
    Enable,
    Disable
} state;
```

### mouse_test.c
console print mouse absolute location [Apple Only]
#### ToDo
* Support Posix

### createImg.h

### lambda.h
```
void (lambda_ptr f)(void) = lambda(
    void, (void){printf("Hello, world!\n");}
);

f();
```

## ToDo
* Support Posix
* Support NT