import numpy as np
import json
from PIL import Image
import matplotlib.pyplot as plt
import torch
import torchvision
from torchvision import models,transforms

imgPath = 'zebra.jpeg'
# 确认版本号 
print("Pytorch Version: ",torch.__version__)
print("Torchvision version: ", torchvision.__version__)

# VGG16已完成训练模型的载入
net = models.vgg16(weights=models.VGG16_Weights.IMAGENET1K_V1)
net.eval()#设置为验证模式

#输出网络结构
print(net)

#定义图片预处理类
class BaseTransform():
    '''
    调整图片尺寸，对颜色进行标准化
    Attribute
    ------------------------------
    resize:调整后图像大小
    mean:各通道颜色均值
    std:各通道颜色方差
    '''
    def __init__(self,resize,mean,std):
        self.base_transform = transforms.Compose([
            transforms.Resize(resize),# 将图片短边映射为resize大小
            transforms.CenterCrop(resize),
            transforms.ToTensor(),#转化为张量
            transforms.Normalize(mean,std)
        ])
    def __call__(self,img):
        return self.base_transform(img)
# 验证处理结果
img = Image.open(imgPath)
plt.imshow(img)
plt.show()

#同时显示预处理前后照片
resize = 224
mean=(0.485,0.456,0.406)
std =(0.229,0.224,0.225)
transform = BaseTransform(resize,mean,std)
img_transformed = transform(img)#3*224*224
#将c*h*w转变为h*w*c，将取值范围限制在0-1
img_transformed = img_transformed.numpy().transpose((1,2,0))
img_transformed = np.clip(img_transformed,0,1)
plt.imshow(img_transformed)
plt.show()


#载入标签
ILSVRC_class_index = json.load(open('imagenet_class_index.json', 'r'))
print(ILSVRC_class_index)

class ILSVRCPredictor():
    '''
    根据ILSVRC数据,从模型的输出结果计算出分类标签
    class_index: dictionary
    '''
    def __init__(self,class_index):
        self.class_index = class_index

    def predict_max(self,out):
        '''
        :paramout:net的输出结果
        :return:预测的分类标签
        '''
        maxid = np.argmax(out.detach().numpy())
        predicted_label_name = self.class_index[str(maxid)][1]
        return predicted_label_name

# 生成ILSVRCPredictor的实例
predictor = ILSVRCPredictor(ILSVRC_class_index)
# 读入图像
img = Image.open(imgPath)
# 进行预处理，添加批次尺寸维度
transform = BaseTransform(resize,mean,std)
img_transformed = transform(img)#已经成为张量
input = img_transformed.unsqueeze_(0)#扩充以为一批

# 将数据输入到模型中进行处理
out = net(input)
result = predictor.predict_max(out)
print("预测的结果是：",result)
