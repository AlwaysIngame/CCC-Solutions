t = int(input())
for x in range(t):
  inp = input().replace("-", "")
  inp = inp[0:10]
  inp = inp.replace("A", "2")
  inp = inp.replace("B", "2")
  inp = inp.replace("C", "2")
  inp = inp.replace("D", "3")
  inp = inp.replace("E", "3")
  inp = inp.replace("F", "3")
  inp = inp.replace("G", "4")
  inp = inp.replace("H", "4")
  inp = inp.replace("I", "4")
  inp = inp.replace("J", "5")
  inp = inp.replace("K", "5")
  inp = inp.replace("L", "5")
  inp = inp.replace("M", "6")
  inp = inp.replace("N", "6")
  inp = inp.replace("O", "6")
  inp = inp.replace("P", "7")
  inp = inp.replace("Q", "7")
  inp = inp.replace("R", "7")
  inp = inp.replace("S", "7")
  inp = inp.replace("T", "8")
  inp = inp.replace("U", "8")
  inp = inp.replace("V", "8")
  inp = inp.replace("W", "9")
  inp = inp.replace("X", "9")
  inp = inp.replace("Y", "9")
  inp = inp.replace("Z", "9")
  inp = list(inp)
  inp.insert(3, "-")
  inp.insert(7, "-")
  inp = "".join(inp)
  print(inp)