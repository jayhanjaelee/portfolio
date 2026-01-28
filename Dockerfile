FROM alpine:latest

LABEL com.hanjaelee.webapp.authors="mail@hanjaelee.com"

COPY . /home/ecewo
WORKDIR /home/ecewo

# requirements -> cmake, gcc and git
RUN apk update && \
      apk add cmake \
      build-base \
      git

RUN mkdir build
RUN chmod u+x ./build.sh && sh ./build.sh

EXPOSE 3000
ENTRYPOINT ["./build/app"]
