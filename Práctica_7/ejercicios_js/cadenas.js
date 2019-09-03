const tok_number = Math.pow(26, 3) * 100;

let str = "";
for (let i = 0; i < tok_number; i++) {
    for (let j = 0; j < 3; j++) {        
        str += String.fromCharCode(Math.trunc(Math.random() * 26 + 65));
    }
    str += " ";
}

const tokens = str.split(" ").filter(token => token === "IPN");
console.log(tokens.length);