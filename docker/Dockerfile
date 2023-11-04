
#########################################################################################
# AML-IP Demos Dockerfile
#########################################################################################

FROM ubuntu:jammy

# Avoids using interactions during building
ENV DEBIAN_FRONTEND=noninteractive

# Use a bash shell so it is possigle to run things like `source` (required for colcon builds)
SHELL ["/bin/bash", "-c"]

ARG amlip_branch="main"

# Avoid interactuation with installation of some package that needs the locale.
ENV TZ=Europe/Madrid
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

# Download system dependencies
RUN apt update && \
    apt install -y software-properties-common && \
    apt update && \
    add-apt-repository ppa:deadsnakes/ppa && \
    apt update && \
    apt install -y \
        cmake \
        g++ \
        git \
        libasio-dev \
        libssl-dev \
        libtinyxml2-dev \
        libyaml-cpp-dev \
        pip \
        swig \
        wget \
        curl \
        swig alsa-utils libopencv-dev
RUN pip3 install -U colcon-common-extensions vcstool
RUN pip3 install -U pyttsx3 opencv-python
RUN pip3 install -U tensorflow \
        tensorflow-hub \
        tensorflow-object-detection-api \
        nvidia-cudnn-cu11==8.6.0.163 \
        protobuf==3.20.*


## Install AML-IP
WORKDIR /AML-IP
RUN mkdir src && \
    wget https://raw.githubusercontent.com/eProsima/AML-IP/$amlip_branch/amlip.repos && \
    vcs import src < amlip.repos && \
    colcon build --packages-up-to-regex amlip
#
RUN colcon build 
## Source built workspace
RUN echo "source /AML-IP/install/setup.bash" >> ~/.bashrc

RUN cd /AML-IP/src/amlip/amlip_demo_nodes/amlip_tensorflow_inference_demo/resource/tensorflow/models/ && \
    wget -O centernet_hourglass_512x512_kpts_1.tar.gz https://tfhub.dev/tensorflow/centernet/hourglass_512x512_kpts/1?tf-hub-format=compressed && \
    mkdir centernet_hourglass_512x512_kpts_1 && \
    tar -xvf centernet_hourglass_512x512_kpts_1.tar.gz -C ./centernet_hourglass_512x512_kpts_1

WORKDIR  /AML-IP/src/amlip/amlip_demo_nodes/amlip_tensorflow_inference_demo/amlip_tensorflow_inference_demo

#Workaround to avoid error when running the demo: AttributeError: module 'tensorflow' has no attribute 'gfile'
#taken from https://stackoverflow.com/questions/55591437/attributeerror-module-tensorflow-has-no-attribute-gfile
RUN sed -i 's/tf.gfile/tf.io.gfile/g' /usr/local/lib/python3.10/dist-packages/object_detection/utils/label_map_util.py

# Vim is always necessary
RUN apt install -y vim
