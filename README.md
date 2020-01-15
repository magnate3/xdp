#My xdp env arch is ft2000 arm64
Install dependencies,the following configuration options are enabled
CONFIG_BPF=y

CONFIG_BPF_SYSCALL=y

CONFIG_NET_CLS_BPF=m

CONFIG_NET_ACT_BPF=m

CONFIG_BPF_JIT=y

CONFIG_HAVE_BPF_JIT=y

CONFIG_BPF_EVENTS=y

or

grep BPF /boot/config-`uname -r`

############################################

centos:

yum install clang llvm -y

yum install elfutils-libelf-devel 

ubuntu:

apt install libelf-dev

apt install clang llvm -y

低版本的clang llvm会报bug：

error: unknown target triple 'bpf', please use -triple or -arch

################ set env####################


ln -s aarch64-linux-gnu/asm/ /usr/include/asm

################ make & install zlib-1.2.8 ####################

./configure

 make && make install
 
 ls /usr/local/include/
 
 ls /usr/local/lib/ 
 
################ common/common.mk ####################

LDFLAGS ?= -L$(LIBBPF_DIR) -L/usr/local/lib

LIBS = -l:libbpf.a -lelf $(USER_LIBS) -lz -l:libz.so.1.2.8


gcc -lz -Wall -I../libbpf/src//build/usr/include/ -g -I../headers/ -L../libbpf/src/ -L/usr/local/lib  -o xdp_pass_user ../common//common_params.o  xdp_pass_user.c -l:libbpf.a -lelf -l:libz.so.1.2.8

