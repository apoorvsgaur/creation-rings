%Designed by Leigh Nelson
function varargout = GUI4(varargin)
% GUI4 MATLAB code for GUI4.fig
%      GUI4, by itself, creates a new GUI4 or raises the existing
%      singleton*.
%
%      H = GUI4 returns the handle to a new GUI4 or the handle to
%      the existing singleton*.
%
%      GUI4('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in GUI4.M with the given input arguments.
%
%      GUI4('Property','Value',...) creates a new GUI4 or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before GUI4_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to GUI4_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help GUI4

% Last Modified by GUIDE v2.5 23-Apr-2013 20:38:54

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @GUI4_OpeningFcn, ...
                   'gui_OutputFcn',  @GUI4_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before GUI4 is made visible.
function GUI4_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to GUI4 (see VARARGIN)

% Choose default command line output for GUI4
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes GUI4 wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = GUI4_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in toLast.
function toLast_Callback(hObject, eventdata, handles)
% hObject    handle to toLast (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
close()
GUI3

% --- Executes on button press in nexSlide.
function nexSlide_Callback(hObject, eventdata, handles)
% hObject    handle to nexSlide (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in ovSlide.
function ovSlide_Callback(hObject, eventdata, handles)
% hObject    handle to ovSlide (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in homeSlide.
function homeSlide_Callback(hObject, eventdata, handles)
% hObject    handle to homeSlide (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in toHome.
function toHome_Callback(hObject, eventdata, handles)
% hObject    handle to toHome (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
close()
nanohubGUI_sec008_team24

% --- Executes on button press in toOv.
function toOv_Callback(hObject, eventdata, handles)
% hObject    handle to toOv (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
close()
overviewGUI_sec008_team24

% --- Executes on button press in toNext.
function toNext_Callback(hObject, eventdata, handles)
% hObject    handle to toNext (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
close()
GUI5


function edit1_Callback(hObject, eventdata, handles)
% hObject    handle to edit1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit1 as text
%        str2double(get(hObject,'String')) returns contents of edit1 as a double


% --- Executes during object creation, after setting all properties.
function edit1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit2_Callback(hObject, eventdata, handles)
% hObject    handle to edit2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit2 as text
%        str2double(get(hObject,'String')) returns contents of edit2 as a double


% --- Executes during object creation, after setting all properties.
function edit2_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit3_Callback(hObject, eventdata, handles)
% hObject    handle to edit3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit3 as text
%        str2double(get(hObject,'String')) returns contents of edit3 as a double


% --- Executes during object creation, after setting all properties.
function edit3_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit4_Callback(hObject, eventdata, handles)
% hObject    handle to edit4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit4 as text
%        str2double(get(hObject,'String')) returns contents of edit4 as a double


% --- Executes during object creation, after setting all properties.
function edit4_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

% --- Executes on button press in pushbutton10.
function pushbutton10_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton10 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton11.
function pushbutton11_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton11 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton12.
function pushbutton12_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton12 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)



function Edit4_Callback(hObject, eventdata, handles)
% hObject    handle to Edit4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of Edit4 as text
%        str2double(get(hObject,'String')) returns contents of Edit4 as a double


% --- Executes during object creation, after setting all properties.
function Edit4_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Edit4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function Edit1_Callback(hObject, eventdata, handles)
% hObject    handle to Edit1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of Edit1 as text
%        str2double(get(hObject,'String')) returns contents of Edit1 as a double


% --- Executes during object creation, after setting all properties.
function Edit1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Edit1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function Edit2_Callback(hObject, eventdata, handles)
% hObject    handle to Edit2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of Edit2 as text
%        str2double(get(hObject,'String')) returns contents of Edit2 as a double


% --- Executes during object creation, after setting all properties.
function Edit2_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Edit2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function Edit3_Callback(hObject, eventdata, handles)
% hObject    handle to Edit3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of Edit3 as text
%        str2double(get(hObject,'String')) returns contents of Edit3 as a double


% --- Executes during object creation, after setting all properties.
function Edit3_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Edit3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in Option1.
function Option1_Callback(hObject, eventdata, handles)
% hObject    handle to Option1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set(handles.Medium_text,'String','This job task means that the scaffold must fill complex 3D defects.');
set(handles.Small_text,'String','Option 1');

% --- Executes on button press in Option2.
function Option2_Callback(hObject, eventdata, handles)
% hObject    handle to Option2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set(handles.Medium_text,'String','This job task means that the scaffold must be able to bear the load forces of surrounding tissue, and then be able to start forming new tissue.');
set(handles.Small_text,'String','Option 2');

% --- Executes on button press in Option3.
function Option3_Callback(hObject, eventdata, handles)
% hObject    handle to Option3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set(handles.Medium_text,'String','This job task means that the scaffold must enhance and control tissue formation, deliver biological information, and be designed for cellular transport.');
set(handles.Small_text,'String','Option 3');

% --- Executes on button press in Option4.
function Option4_Callback(hObject, eventdata, handles)
% hObject    handle to Option4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set(handles.Medium_text,'String','This job task means that the scaffold must be securely fixed to surrounding tissue.');
set(handles.Small_text,'String','Option 4');

% --- Executes during object creation, after setting all properties.
function Big_text_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Big_text (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called


% --- Executes on button press in Check.
function Check_Callback(hObject, eventdata, handles)
% hObject    handle to Check (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set(handles.Small_text,'String',' ');% reset the title to blank

%get the choice made by the users
ans1 = get(handles.Dropbox1,'Value') - 1;
ans2 = get(handles.Dropbox2,'Value') - 1;
ans3 = get(handles.Dropbox3,'Value') - 1;
ans4 = get(handles.Dropbox4,'Value') - 1;

%check if all choice made
work = ans1 * ans2 * ans3 * ans4;

%preset string array
notCorr = [];
notSelect = [];
err = [];
error = [];
i = 1;%array index for notCorr or notSelect

if work
   corr = ans1 == 1 && ans2 == 4 && ans3 == 2 && ans4 == 3; %all corret
  if corr
      set(handles.Medium_text,'String','Correct!')%Correct!!!
  else
      if ans1 ~= 1
          notCorr{i} = 'Form';
          i = i + 1;
      end
      if ans2 ~= 4
          notCorr{i} = 'Fixation';
          i = i + 1;
      end
      if ans3 ~= 2
          notCorr{i} = 'Function';
          i = i + 1;
      end
      if ans4 ~= 3
          notCorr{i} = 'Formation';
          i = i + 1;
      end
      error = ['Following option(s) not correct:' notCorr];%initialize error message
      set(handles.Medium_text,'String',error)%report error
end
end

if ~work
    if ~ans1
        notSelect{i} = 'Form ';
        i = i + 1;
    end
    if ~ans2
        notSelect{i} = 'Fixation ';
        i = i + 1;
    end
    if ~ans3
        notSelect{i} = 'Function ';
        i = i + 1;
    end
    if ~ans4
        notSelect{i} = 'Formation ';
        i = i + 1;
    end
    err = ['Following option(s) not selected:' notSelect];%initialize error message
    set(handles.Medium_text,'String',err)%report error
end


% --- Executes on selection change in Dropbox1.
function Dropbox1_Callback(hObject, eventdata, handles)
% hObject    handle to Dropbox1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns Dropbox1 contents as cell array
%        contents{get(hObject,'Value')} returns selected item from Dropbox1

%Check if choice made overlap with others
if get(handles.Dropbox2,'Value') == get(hObject,'Value')
    set(handles.Dropbox2,'Value',1);%rest option
end

if get(handles.Dropbox3,'Value') == get(hObject,'Value')
    set(handles.Dropbox3,'Value',1);%rest option
end

if get(handles.Dropbox4,'Value') == get(hObject,'Value')
    set(handles.Dropbox4,'Value',1);%rest option
end

% --- Executes during object creation, after setting all properties.
function Dropbox1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Dropbox1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in Dropbox2.
function Dropbox2_Callback(hObject, eventdata, handles)
% hObject    handle to Dropbox2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns Dropbox2 contents as cell array
%        contents{get(hObject,'Value')} returns selected item from Dropbox2

%Check if choice made overlap with others
if get(handles.Dropbox1,'Value') == get(hObject,'Value')
    set(handles.Dropbox1,'Value',1);%rest option
end

if get(handles.Dropbox3,'Value') == get(hObject,'Value')
    set(handles.Dropbox3,'Value',1);%rest option
end

if get(handles.Dropbox4,'Value') == get(hObject,'Value')
    set(handles.Dropbox4,'Value',1);%rest option
end


% --- Executes during object creation, after setting all properties.
function Dropbox2_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Dropbox2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in Dropbox3.
function Dropbox3_Callback(hObject, eventdata, handles)
% hObject    handle to Dropbox3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns Dropbox3 contents as cell array
%        contents{get(hObject,'Value')} returns selected item from Dropbox3

%Check if choice made overlap with others
if get(handles.Dropbox1,'Value') == get(hObject,'Value')
    set(handles.Dropbox1,'Value',1);%reset option
end

if get(handles.Dropbox2,'Value') == get(hObject,'Value')
    set(handles.Dropbox2,'Value',1);%reset option
end

if get(handles.Dropbox4,'Value') == get(hObject,'Value')
    set(handles.Dropbox4,'Value',1);%reset option
end


% --- Executes during object creation, after setting all properties.
function Dropbox3_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Dropbox3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in Dropbox4.
function Dropbox4_Callback(hObject, eventdata, handles)
% hObject    handle to Dropbox4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns Dropbox4 contents as cell array
%        contents{get(hObject,'Value')} returns selected item from Dropbox4

%Check if choice made overlap with others
if get(handles.Dropbox2,'Value') == get(hObject,'Value')
    set(handles.Dropbox2,'Value',1);%reset option
end

if get(handles.Dropbox3,'Value') == get(hObject,'Value')
    set(handles.Dropbox3,'Value',1);%reset option
end

if get(handles.Dropbox1,'Value') == get(hObject,'Value')
    set(handles.Dropbox1,'Value',1);%reset option
end


% --- Executes during object creation, after setting all properties.
function Dropbox4_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Dropbox4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
