class ProductOfNumbers:

    def __init__(self):
        self.products = []

    def add(self, num: int) -> None:
        if num == 0:
            self.products = []
        else:
            if len(self.products) == 0:
                self.products.append(num)
            else:
                self.products.append(num * self.products[-1])

    def getProduct(self, k: int) -> int:
        if k < len(self.products):
            return self.products[-1] // self.products[len(self.products) - k - 1]
        elif k == len(self.products):
            return self.products[-1]
        else:
            return 0
