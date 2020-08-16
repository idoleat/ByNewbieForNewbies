//woohoo ES6!
class book {
  constructor(title, auther, year) {
    this.title = title;
    this.auther = auther;
    this.year = year;
  }

  getSummary() {
    return `${this.title} is written by ${this.auther} in ${this.year}`;
  }

  getAge() {
    return `this book is ${2020 - this.year} old`;
  }
}

//instantiate
const book1 = new book("kill me plz", "me la", "2020");
console.log(book1);
console.log(book1.getSummary());
console.log(book1.getAge());

//subclass(not inheritant?)
class magzone extends book {
  constructor(titile, auther, year, month) {
    super(titile, auther, year);
    this.month = month;
  }
}

const mag1 = new magzone("mag", "It's me, man, It's me!", "2998");
console.log(mag1);
console.log(mag1.getSummary());

//There are many ways in Js to doo oop stuff
//Maybe follow the framework you're using will be great
