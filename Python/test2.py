def cube(number):
    cubedno = number ** 3
    number = cubedno
    print number
    return number

def by_three(number):
    if number % 3 == 0:
        return cube(number)
    else:
        print False
        print number
        return False

cube(3)
by_three(3)
