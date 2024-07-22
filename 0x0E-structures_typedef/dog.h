#ifndef DOG_H
#define DOG_H

/**
 * struct dog - a dog's basic info
 * @name: The name of the dog
 * @age: The age of the dog
 * @owner: The owner of the dog
 *
 * Description: This structure holds basic information about a dog,
 * including its name, age, and owner. The `name` and `owner` are
 * pointers to strings, while `age` is a floating-point number representing
 * the dog's age in years.
 */
struct dog
{
    char *name;
    float age;
    char *owner;
};

/**
 * dog_t - typedef for struct dog
 */
typedef struct dog dog_t;

#endif /* DOG_H */

