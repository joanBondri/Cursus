From debian:buster
RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get -y install wget
RUN apt-get -y install nginx
RUN apt-get -y install mariadb-server
RUN apt-get -y install php7.3 php-mysql php-fpm php-pdo php-gd php-cli php-mbstring
RUN openssl req -x509 -nodes -days 365 -subj "/C=FR/ST=France/L=Paris/O=42Paris/OU=42Paris/CN=jbondri" -newkey rsa:2048 -keyout /etc/ssl/nginx-selfsigned.key -out /etc/ssl/nginx-selfsigned.crt;
COPY ./srcs/wp-config.php /var/www/html
COPY ./srcs/config.inc.php /
COPY ./srcs/fichier.php /
COPY ./srcs/init.sh /
COPY ./srcs/default /etc/nginx/site-available/default
CMD bash init.sh
