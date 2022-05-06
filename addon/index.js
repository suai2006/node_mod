const filesystem = require('./build/Release/fs');
class fs{

    static scanDir(path, callback){
        if(!!callback) callback(filesystem.scanDir(path));
        return;
    }
    
    static async asyncScanDir(path){
        try {
            return filesystem.scanDir(path);
        } catch (error) {
            return error;
        }
    }

    // получаем файл, и возвращаем его содержимое
    static readFile(file, callback){
        if(!!callback) callback(filesystem.readFile(file));
        return;
    }

    // получаем файл, и записываем в него
    static writeToFile(file, data){
        return filesystem.writeToFile(file, data);
    }

    // получаем файл, но не читаем
    static fopen(filepath, callback){
        let path = process.cwd();
        if(filepath.indexOf("..").length > 0){
            // пасим путь
            let wayList = filepath.split("/").filter(f => f == "..");
            let wayFinder = path.split("/");
            console.log(path, filepath);
        }
        let list = filepath.split("/");
        let fileName = list[list.length - 1];
        let data = filesystem.fopen(`${path}/${fileName}`);
        if(!!callback) callback(data);
    }

    // построчное чтение, возвращаем строку
    static fread(file, n){
        return filesystem.fread(file, n);
    }
}
module.exports = fs;