
class Star:
   def __init__(self, name, color):
        self.name = name
        self.color = color
s1 = Star("star_first", "yellow")

print(s1.name, s1.color)

class Monitor:
    def __init__(self, brand, size, color, shape):
        self.brand = brand
        self.size = size
        self.color = color
        self.shape = shape
m1 = Monitor("philips", 23, "black", "flat")
             
print(m1.brand, m1.size, m1.color, m1.shape)