
function Hello(){
	var age;
	this.setAge = function(thyAge){
		age = thyAge;	
	};
	this.introduceAge = function(){
		console.log('hello,i am '+age +'years old');

	}
};
exports.Hello=Hello;
var name;
exports.setName = function(thyName){
	name = thyName;
};
exports.introduceName = function(){
	console.log('hello,my name is '+name);
};


function Hello(){
	var age;
	this.setAge = function(thyAge){
		age = thyAge;	
	};
	this.introduceAge = function(){
		console.log('hello,i am '+age +'years old');

	}
};
