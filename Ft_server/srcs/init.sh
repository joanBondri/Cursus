
chown -R www-data:www-data *
chmod -R 755 /var/www/*

wget https://files.phpmyadmin.net/phpMyAdmin/5.0.1/phpMyAdmin-5.0.1-english.tar.gz
tar -xf phpMyAdmin-5.0.1-english.tar.gz && rm -rf phpMyAdmin-5.0.1-english.tar.gz
mv phpMyAdmin-5.0.1-english phpmyadmin
cp ./config.inc.php phpmyadmin/config.inc.php

wget https://wordpress.org/latest.tar.gz
tar -xvzf latest.tar.gz && rm -rf latest.tar.gz

#service mariadb-server start
service mysql start
# Configure a wordpress database
echo "CREATE DATABASE wordpress;"| mysql -u root
echo "CREATE USER 'test'@'%';" | mysql -u root
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'test'@'%' WITH GRANT OPTION;"| mysql -u root
echo "FLUSH PRIVILEGES;"| mysql -u root
#echo "update mysql.user set plugin='' where user='root';"| mysql -u root --skip-password

service nginx start
service php7.3-fpm start
bash
