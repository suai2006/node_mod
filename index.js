import fs from './addon/index.js'

let path = process.cwd();
console.log("\nfs.scanDir\n");
fs.scanDir(path,(data)=>{
    console.log(`\nчитаем файлы каталога ${path}\n`);
    for(let [key, val] of Object.entries(data)){        
        if(val == "isFile"){
            if(key == "index.js") continue;
            fs.fopen("./" + key, (data) => {
                // получили содержимое файла
                console.log(`\nполучили содержимое файла ${key}\n`);
                console.log(data);
            });
        }
    }
});

