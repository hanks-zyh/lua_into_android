package hanks.pub.luajava_android;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

import com.luajava.LuaState;
import com.luajava.LuaStateFactory;

public class MainActivity extends AppCompatActivity {

    private EditText et_num1;
    private EditText et_num2;
    private TextView tv_result;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        et_num1 = (EditText) findViewById(R.id.et_num1);
        et_num2 = (EditText) findViewById(R.id.et_num2);
        tv_result = (TextView) findViewById(R.id.tv_result);
        findViewById(R.id.btn_calc).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                int n1 = Integer.parseInt(et_num1.getText().toString());
                int n2 = Integer.parseInt(et_num2.getText().toString());

                LuaState L = LuaStateFactory.newLuaState();
                L.openLibs();
                L.LdoString("function power(a,n) return a^n end");
                L.getGlobal("power");
                L.pushInteger(n1);
                L.pushInteger(n2);
                L.call(2, 1);

                long v = L.toInteger(-1);
                tv_result.setText(n1 + "^" + n2 + " = " + v);
            }
        });


    }
}
