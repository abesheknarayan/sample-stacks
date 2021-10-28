FROM ubuntu:latest

## RUN runs during build
RUN apt-get update && \
    apt-get install -y apt-utils \
    zip \
    unzip \
    vim \
    curl \
    netcat \ 
    build-essential

WORKDIR /sample-stacks
COPY . .


# runs only when docker run is executed
CMD ["bash","docker-build.sh"]
