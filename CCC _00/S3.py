class website:
    def __init__(self, url):
        self.url = url
        self.links = []
        self.code = ""


sites = []
def findlink(url1, url2, visited):
    if url1 in visited:
        return False
    visited.append(url1)
    si = next(x for x in sites if x.url == url1)
    tem = []
    if url2 in si.links:
        return True
    else:
        for _ in si.links:
            tem.append(findlink(_, url2, visited))
        if True in tem:
            return True
    return False
for _ in range(int(input())):
    site = website(input())
    while True:
        site.code += input()
        if site.code.endswith("</HTML>"):
            break
    for ind in range(len(site.code)):
        if site.code[ind] == "<":
            if site.code[ind+1] == "A" and site.code[ind+2] == " ":
                n = site.code.find('\"', ind)+1
                site.links.append(site.code[n:site.code.find('\"', n+1)])
    sites.append(site)

for site in sites:
    for link in site.links:
        print("Link from " + site.url + " to " + link)

while True:
    inp = input()
    if inp == "The End":
        break
    inp2 = input()
    if findlink(inp, inp2, []):
        print("Can surf from " + inp + " to " + inp2 + ".")
    else:
        print("Can't surf from " + inp + " to " + inp2 + ".")