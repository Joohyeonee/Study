FROM nvcr.io/nvidia/tensorrt:22.05-py3

SHELL ["/bin/bash", "-c"]

# Setup user account
# id -g, id -u
ARG uid=1006
ARG gid=1006
RUN groupadd -r -f -g ${gid} jhlee && useradd -o -r -l -u ${uid} -g ${gid} -ms /bin/bash jhlee
RUN usermod -aG sudo jhlee
RUN echo 'jhlee:jhlee1' | chpasswd
RUN mkdir -p /workspace && chown jhlee /workspace

# Required to build Ubuntu 20.04 without user prompts with DLFW container
ENV DEBIAN_FRONTEND=noninteractive

# locale Korean
RUN apt-get update
RUN apt-get install -y locales
RUN locale-gen ko_KR.UTF-8
ENV LC_ALL ko_KR.UTF-8

WORKDIR /workspace

USER jhlee
RUN ["/bin/bash"]