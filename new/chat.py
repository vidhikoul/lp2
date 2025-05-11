import gradio as gr
from nltk.chat.util import Chat, reflections

# Define chatbot rules using regex patterns
pairs = [
    # Greetings
    [r"hi|hello|hey|greetings|wassup", ["Hello! Welcome to CafeBot. How can I help you today?"]],
    [r"how are you", ["I'm brewing good vibes! How can I serve you today?"]],
    # means it's a raw string literal in Python.
    # Menu
    [r"(.*)menu(.*)", ["Here's our menu:\n\n☕ Coffee:\n- Espresso ₹100\n- Americano ₹120\n- Latte ₹150\n- Cappuccino ₹150\n- Mocha ₹160\n- Flat White ₹160\n\n🍵 Tea:\n- Black Tea ₹90\n- Green Tea ₹100\n- Herbal Tea ₹110\n- Chai Latte ₹120\n\n🥐 Pastries & Snacks:\n- Muffin ₹70\n- Croissant ₹80\n- Chocolate Cake ₹90\n- Sandwich ₹120"]],
    
    # Specials
    [r"(.*)special(.*)|deal|combo|today", ["Today's special is Hazelnut Mocha (₹170) and Spinach-Corn Sandwich (₹130)."]],
    
    # Coffee
    [r"(.*)coffee(.*)|espresso|latte|cappuccino|mocha|americano", ["We offer a variety of coffee:\n- Espresso ₹100\n- Americano ₹120\n- Latte ₹150\n- Cappuccino ₹150\n- Mocha ₹160\n- Flat White ₹160"]],
    
    # Tea
    [r"(.*)tea(.*)|green|herbal|black|chai", ["Our tea options:\n- Black Tea ₹90\n- Green Tea ₹100\n- Herbal Tea ₹110\n- Chai Latte ₹120"]],
    
    # Snacks
    [r"(.*)food(.*)|snack|pastry|muffin|croissant|cake|sandwich", ["Here's what we have to eat:\n- Muffin ₹70\n- Croissant ₹80\n- Chocolate Cake ₹90\n- Sandwich ₹120"]],
    
    # WiFi
    [r"(.*)wifi(.*)|internet|network|password", ["Yes, we offer free WiFi. Network: CafeConnect_Guest, Password: enjoyyourcoffee"]],
    
    # Payment
    [r"(.*)pay(.*)|payment|card|cash|upi|gpay|paytm|phonepe", ["We accept cash, card, and UPI (GPay, PhonePe, Paytm)."]],
    
    # Vegan/Allergies
    [r"(.*)vegan(.*)|vegetarian|allergy|gluten|milk|dairy|almond|soy|oat", ["We offer oat/almond milk and vegetarian snacks. Let us know about allergies!"]],
    
    # Restroom
    [r"(.*)restroom(.*)|bathroom|toilet|washroom", ["Restroom is past the counter to the left."]],
    
    # Hours
    [r"(.*)open(.*)|hour|timing|close|time", ["We’re open daily from 8:00 AM to 8:00 PM."]],
    
    # Location
    [r"(.*)location(.*)|address|where", ["We’re located at 15 Cafe Lane, Koregaon Park, Pune."]],
    
    # Bye
    [r"bye|goodbye|exit|quit", ["Goodbye! Hope to see you again at CafeBot ☕"]],
    
    # Fallback
    [r"(.*)", ["Sorry, I didn’t catch that. You can ask about our menu, coffee, tea, specials, hours, or location."]],
]

# Create Chat instance
chatbot = Chat(pairs, reflections)

# Define response function
def respond(message, history):
    return chatbot.respond(message)

# Gradio Chat Interface
demo = gr.ChatInterface(
    fn=respond,
    title="☕ CafeBot",
    description="Ask me about coffee, tea, food, menu, specials, hours, WiFi, and more!",
    # theme="huggingface",
    theme="soft",
    examples=["Show me the menu", "What's the special today?", "Do you have WiFi?", "What time do you open?"]
)

# Launch app
demo.launch()
