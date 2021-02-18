##1
library(readxl)
SdA_HW <- read_excel("D:/MASA/DERS/3.sýnýf-1/istatistiksel veri analizi/proje/SdA-HW.xls")
View(SdA_HW)


##2
SdA_HW$type=as.factor(SdA_HW$type)
SdA_HW <- SdA_HW[-5]

n <- which(is.na(SdA_HW$rrt))
SdA_HW <- SdA_HW[-n,]
n <- which(is.na(SdA_HW$frt))
SdA_HW <- SdA_HW[-n,]
View(SdA_HW)


##3
type1 <- subset(SdA_HW,subset = (type ==1) )
type2 <- subset(SdA_HW,subset = (type ==2) )
View(type1)
View(type2)

fivenum(type1)
summary(type1)
fivenum(type2)
summary(type2)


##4
boxplot(type1[,2:6], main = "type = 1 için")
boxplot(type2[,2:6], main = "type = 2 için")


##5
hist(type1$tpthrt, main = "type = 1 için")
hist(type1$pkthrt, main = "type = 1 için")
hist(type1$dfdrrt, main = "type = 1 için")
hist(type1$rrt, main = "type = 1 için")
hist(type1$frt, main = "type = 1 için")

hist(type2$tpthrt, main = "type = 2 için")
hist(type2$pkthrt, main = "type = 2 için")
hist(type2$dfdrrt, main = "type = 2 için")
hist(type2$rrt, main = "type = 2 için")
hist(type2$frt, main = "type = 2 için")


##6
normalize <- function(x){
  return ((x - min(x)) / (max(x) - min(x)))
}

type1$tpthrt <- normalize(type1$tpthrt)
type1$pkthrt <- normalize(type1$pkthrt)
type1$dfdrrt <- normalize(type1$dfdrrt)
type1$rrt <- normalize(type1$rrt)
type1$frt <- normalize(type1$frt)

type2$tpthrt <- normalize(type2$tpthrt)
type2$pkthrt <- normalize(type2$pkthrt)
type2$dfdrrt <- normalize(type2$dfdrrt)
type2$rrt <- normalize(type2$rrt)
type2$frt <- normalize(type2$frt)

plot(type1$tpthrt, type = "o", col = "red", ylab = "tpthrt", main = " red -> type=1    blue -> type=2")
lines(type2$tpthrt, type = "o", col = "blue")
plot(type1$pkthrt, type = "o", col = "red", ylab = "pkthrt", main = " red -> type=1    blue -> type=2")
lines(type2$pkthrt, type = "o", col = "blue")
plot(type1$dfdrrt, type = "o", col = "red", ylab = "dfdrrt", main = " red -> type=1    blue -> type=2")
lines(type2$dfdrrt, type = "o", col = "blue")
plot(type1$rrt, type = "o", col = "red", ylab = "rrt", main = " red -> type=1    blue -> type=2")
lines(type2$rrt, type = "o", col = "blue")
plot(type1$frt, type = "o", col = "red", ylab = "frt", main = " red -> type=1    blue -> type=2")
lines(type2$frt, type = "o", col = "blue")


##7
cor(type1$tpthrt,type1$pkthrt, method = "kendall")
cor(type2$tpthrt,type2$pkthrt)
cor(type1[1:64,2],type2$tpthrt)
