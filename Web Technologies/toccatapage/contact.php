<!DOCTYPE html>

<html lang="en" xmlns="http://www.w3.org/1999/xhtml">
    <head>
        <meta charset="utf-8" />

        <title>
            Contact
        </title>

        <link rel="stylesheet" href="resources/sprung.css" />
    </head>

    <body>
        <div class="sidenav">
            <img src="images/logo_small.jpg" alt="Toccatatones Logo" height="100" width="100" />

            <a href="index.html">
                Home
            </a>
            <a href="about.html">
                About
            </a>
            <a href="members.html">
                Members
            </a>
            <a href="socials.html">
                Socials
            </a>
            <a href="events.html">
                Events
            </a>
            <a href="contact.html">
                Contact Us
            </a>
            <a href="help.html">
                FAQ
            </a>

            <img src="images/logo_small.jpg" alt="Toccatatones Logo" height="100" width="100" />
        </div>
        
        <div class="content">
            <h1>
                Contact Us
            </h1>
            <br />
            <div class="container">
                <form action="contact_submit.php" method="post" id="contact_submit">
                    <label for="fname">
                        First Name
                    </label>
                    <input type="text" id="fname" name="firstname" placeholder="Your first name..">

                    <label for="lname">
                        Last Name
                    </label>
                    <input type="text" id="lname" name="lastname" placeholder="Your last name..">

                    <label for="number">
                        Phone Number
                    </label>
                    <input type="text" id="number" name="phonenumber" placeholder="Your phone number..." />

                    <label for="state">
                        State
                    </label>
                    <select id="state" name="state">
                        <option value="AL">Alabama</option>
                        <option value="AK">Alaska</option>
                        <option value="AZ">Arizona</option>
                        <option value="AR">Arkansas</option>
                        <option value="CA">California</option>
                        <option value="CO">Colorado</option>
                        <option value="CT">Connecticut</option>
                        <option value="DE">Delaware</option>
                        <option value="DC">Dist of Columbia</option>
                        <option value="FL">Florida</option>
                        <option value="GA">Georgia</option>
                        <option value="HI">Hawaii</option>
                        <option value="ID">Idaho</option>
                        <option value="IL">Illinois</option>
                        <option value="IN">Indiana</option>
                        <option value="IA">Iowa</option>
                        <option value="KS">Kansas</option>
                        <option value="KY">Kentucky</option>
                        <option value="LA">Louisiana</option>
                        <option value="ME">Maine</option>
                        <option value="MD">Maryland</option>
                        <option value="MA">Massachusetts</option>
                        <option value="MI">Michigan</option>
                        <option value="MN">Minnesota</option>
                        <option value="MS">Mississippi</option>
                        <option value="MO">Missouri</option>
                        <option value="MT">Montana</option>
                        <option value="NE">Nebraska</option>
                        <option value="NV">Nevada</option>
                        <option value="NH">New Hampshire</option>
                        <option value="NJ">New Jersey</option>
                        <option value="NM">New Mexico</option>
                        <option value="NY">New York</option>
                        <option value="NC">North Carolina</option>
                        <option value="ND">North Dakota</option>
                        <option value="OH">Ohio</option>
                        <option value="OK">Oklahoma</option>
                        <option value="OR">Oregon</option>
                        <option value="PA">Pennsylvania</option>
                        <option value="RI">Rhode Island</option>
                        <option value="SC">South Carolina</option>
                        <option value="SD">South Dakota</option>
                        <option value="TN">Tennessee</option>
                        <option value="TX">Texas</option>
                        <option value="UT">Utah</option>
                        <option value="VT">Vermont</option>
                        <option value="VA">Virginia</option>
                        <option value="WA">Washington</option>
                        <option value="WV">West Virginia</option>
                        <option value="WI">Wisconsin</option>
                        <option value="WY">Wyoming</option>
                    </select>

                    <label for="subject">
                        Subject
                    </label>
                    <textarea id="subject" name="subject" placeholder="Write something.." style="height:200px" maxlength="1000"></textarea>

                    <input type="submit" value="Submit">
                </form>
            </div>
        </div>

        <div class="footer">
            <p>
                &copy; 2022 Toccatatones
            </p>
        </div>
    </body>
</html>