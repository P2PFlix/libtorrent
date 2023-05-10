FROM zouzias/boost:1.67.0

RUN apt remove --purge --auto-remove cmake && \
    apt install -y software-properties-common lsb-release && \
    apt clean all && \
    wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null | gpg --dearmor - | tee /etc/apt/trusted.gpg.d/kitware.gpg >/dev/null && \
    apt-add-repository "deb https://apt.kitware.com/ubuntu/ $(lsb_release -cs) main" && \
    apt update && apt install kitware-archive-keyring && rm /etc/apt/trusted.gpg.d/kitware.gpg && \
    apt update && apt install -y cmake curl 

COPY . /app

# RUN groupadd -r user && useradd -g tom tom 
# RUN chown -R tom:tom /app
COPY . /app
# USER tom

RUN curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.35.3/install.sh | bash && \
    nvm install 16.15.1 && \
    export NVM_DIR="$HOME/.nvm" && \
    [ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh" && \
    [ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh" 

CMD ["bash"]