import requests
def great_function(i):
    f = open('NASA3.jpg','wb')
    response = requests.get('http://www.python.org/images/success/nasa.jpg')
    f.write(response.content)
    f.close()
    return i

# f()
# print("download successful")