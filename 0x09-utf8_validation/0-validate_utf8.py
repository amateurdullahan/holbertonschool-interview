#!/usr/bin/python3
""" Validate da UTF8 """


def validUTF8(data):

    if type(data) is not list:
        return False

    byteList = []

    for num in data:
        try:
            byteList.append(num.to_bytes(1, 'big'))
        except OverflowError:
            byteList.append(num.to_bytes(2, 'big'))
    test = b''.join(byteList)

    try:
        test.decode('utf-8')
    except UnicodeDecodeError:
        return False

    return True
