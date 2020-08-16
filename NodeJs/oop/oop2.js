//create a obj
const bookProto = {
  getSummant: function() {
    return `${this.title} is written by ${this.auther} in ${this.year}`;
  },
  getAge: function() {
    return `this book is ${2020 - this.year} old`;
  }
};

const book1 = Object.create(bookProto); //"new" way is for constructors
console.log(book1);
console.log(book1.getSummant());
book1.title = "wahaha";
book1.auther = "me la";
book1.year = "1990";
console.log(book1.getSummant());
