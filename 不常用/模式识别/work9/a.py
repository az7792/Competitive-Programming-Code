import cv2
import numpy as np
import os
from sklearn.cluster import KMeans
from sklearn.decomposition import PCA
import matplotlib.pyplot as plt

# 读取图片
def read_and_preprocess_images(folder_path, prefix, num_images):
    images = []
    for i in range(1, num_images+1):
        img_path = os.path.join(folder_path, f'{prefix}{i}.jpg')
        img = cv2.imread(img_path)
        if img is not None:
            img_rgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
            images.append(img_rgb)
    return images

# 提取图像特征
def extract_features(images):
    features = []
    for img in images:
        resized_img = cv2.resize(img, (500, 500))
        features.append(resized_img)
    return features

# 使用KMeans进行聚类
def kmeans_clustering(features, num_clusters):
    reshaped_features = np.reshape(features, (len(features), -1))
    kmeans = KMeans(n_clusters=num_clusters)
    kmeans.fit(reshaped_features)
    return kmeans.labels_

# 使用ISODATA方法进行聚类
def isodata_clustering(features, num_clusters):
    features_array = np.array(features)
    reshaped_features = np.reshape(features_array, (len(features_array), -1))
    
    # 使用PCA降维
    pca = PCA(n_components=2)
    features_pca = pca.fit_transform(reshaped_features)
    
    # 使用KMeans对降维后的数据进行聚类
    kmeans = KMeans(n_clusters=num_clusters)
    kmeans.fit(features_pca)
    return kmeans.labels_

# 读取猫、狗和大象的图片
cat_images = read_and_preprocess_images("cats", "cat", 15)
dog_images = read_and_preprocess_images("dogs", "dog", 15)
elephant_images = read_and_preprocess_images("elephants", "elephant", 15)

images = cat_images + dog_images + elephant_images

# 提取图像特征
features = extract_features(images)

# 使用KMeans进行聚类
kmeans_labels = kmeans_clustering(features, 3)

# 使用ISODATA进行聚类
isodata_labels = isodata_clustering(features, 3)

print(kmeans_labels)
print(isodata_labels)

# 根据标签分割图像
def split_images_by_label(images, labels):
    split_images = [[] for _ in range(max(labels) + 1)]
    for i in range(45):
        split_images[labels[i]].append(images[i])
    return split_images


def show_images(tmp_images):
    num_cols = len(tmp_images)
    fig, axes = plt.subplots(1, num_cols, figsize=(12, 6))
    for i, img in enumerate(tmp_images):
        axes[i].imshow(img)
        axes[i].axis('off')
    plt.show()


# 根据KMeans聚类结果分割图像并展示
kmeans_split_images = split_images_by_label(images, kmeans_labels)
for tmp_images in kmeans_split_images:
    show_images(tmp_images)

# 根据ISODATA聚类结果分割图像并展示
isodata_split_images = split_images_by_label(images, isodata_labels)
for tmp_images in isodata_split_images:
    show_images(tmp_images)
