function Hello(){
	var name;
	this.setName = function(thyName){
		name = thyName;
	};
	this.sayHello = function(){
		conlole.log('Hello '+name);
	};
};
module.exports = Hello;
