def r_sort(str_list):
    rev = sorted(str_list, key=lambda x: x[::-1])
    return rev


if __name__ == "__main__":
    strings = ["i", "love", "c++"]
    print(r_sort(strings))

