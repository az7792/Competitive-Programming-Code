import os
import shutil

def extract_unique_files(source_dir, destination_dir, reference_dir):
    # 获取源文件夹中的所有文件列表
    source_files = set(os.listdir(source_dir))
    
    # 获取参考文件夹中的所有文件列表
    reference_files = set(os.listdir(reference_dir))
    
    # 计算不在参考文件夹中的文件列表
    unique_files = source_files - reference_files
    
    # 将不在参考文件夹中的文件复制到目标文件夹
    for filename in unique_files:
        source_path = os.path.join(source_dir, filename)
        destination_path = os.path.join(destination_dir, filename)
        shutil.copy(source_path, destination_path)
        print(f"File '{filename}' copied to '{destination_dir}'")

# 源文件夹路径
source_folder = "./a"
# 目标文件夹路径
destination_folder = "./c"
# 参考文件夹路径
reference_folder = "./b"

# 调用函数进行文件提取
extract_unique_files(source_folder, destination_folder, reference_folder)
