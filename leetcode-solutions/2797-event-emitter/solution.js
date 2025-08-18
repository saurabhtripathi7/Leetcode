class EventEmitter {
    constructor(){
        this.events = {};
    }
    /**
     * @param {string} eventName
     * @param {Function} callback
     * @return {Object}
     */
    subscribe(eventName, callback) {
        // If this event doesn't exist yet in the events object,
        // init it with empty array
        if(!this.events[eventName]){
            this.events[eventName] = [];
        }
        // Add (push) the new callback function into this event's list
        this.events[eventName].push(callback);


        // Return an object that contains an unsubscribe method
        return {
            unsubscribe: () => {
                this.events[eventName] = this.events[eventName].filter(cbFn => cbFn !== callback);
                return undefined; //req in ques
            }
        };
    }
    
    /**
     * @param {string} eventName
     * @param {Array} args
     * @return {Array}
     */
    emit(eventName, args = []) {
        if(!this.events[eventName]) return [];

        const res = [];
        this.events[eventName].forEach((cbFn)=>{
            res.push(cbFn(...args));
        });
        return res;
    }
}

/**
 * const emitter = new EventEmitter();
 *
 * // Subscribe to the onClick event with onClickCallback
 * function onClickCallback() { return 99 }
 * const sub = emitter.subscribe('onClick', onClickCallback);
 *
 * emitter.emit('onClick'); // [99]
 * sub.unsubscribe(); // undefined
 * emitter.emit('onClick'); // []
 */
