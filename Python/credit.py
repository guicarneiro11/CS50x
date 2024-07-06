from cs50 import get_string


def main():
    card_number = get_string("Number: ")
    if is_valid(card_number):
        card_type = get_card_type(card_number)
        print(card_type)
    else:
        print("INVALID")


def is_valid(card_number):

    sum_doubled_digits = 0
    for i in range(len(card_number) - 2, -1, -2):
        digit = int(card_number[i]) * 2
        sum_doubled_digits += digit // 10 + digit % 10

    sum_other_digits = 0
    for i in range(len(card_number) - 1, -1, -2):
        sum_other_digits += int(card_number[i])

    total_sum = sum_doubled_digits + sum_other_digits
    return total_sum % 10 == 0


def get_card_type(card_number):
    if len(card_number) == 15 and card_number.startswith(("34", "37")):
        return "AMEX"
    elif len(card_number) == 16 and card_number.startswith(("51", "52", "53", "54", "55")):
        return "MASTERCARD"
    elif len(card_number) in (13, 16) and card_number.startswith("4"):
        return "VISA"
    else:
        return "INVALID"


if __name__ == "__main__":
    main()
