from PIL import Image

# 打开.tif图像文件
tif_image = Image.open('wirebond-mask.tif')

# 将图像保存为.jpg格式
tif_image.save('wirebond-mask.jpg')

print("Conversion complete!")
