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
example/raw_mode_test.c
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
```void writeImg(image img);```
```
typedef struct Image
{
    char *image_name;
    int scale;
    array2d raw;
} image;
```
```
typedef struct Array2d
{
    int width, height, *data;
} array2d;
```

### lambda.h
example/lambda.c
```
void (lambda_ptr f)(void) = lambda(
    void, (void){printf("Hello, world!\n");}
);

f();
```

## ToDo
* Support Posix
* Support NT